#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Point{
    int x;
    int y;
};

struct Data{
    int pointNo;
    struct Point value;
    int otherCoordInd;
};

void sortData(struct Data *data, int size, int x){

    if(size <= 1)
        return;

    sortData(data, size / 2, x);
    sortData(data + (size / 2), size - (size / 2), x);

    struct Data *leftData = (struct Data*)malloc(sizeof(struct Data) * (size / 2));
    for(int ind = 0; ind < size / 2; ind++)
        leftData[ind] = data[ind];
    
    struct Data *rightData = (struct Data*)malloc(sizeof(struct Data) * (size - (size / 2)));
    for(int ind = size / 2; ind < size; ind++)
        rightData[ind - (size / 2)] = data[ind];

    struct Data *combineData = (struct Data*)malloc(sizeof(struct Data) * size);
    int ptr1 = 0, ptr2 = 0;
    int ptr3 = 0;
    while(ptr1 < (size / 2) && ptr2 < (size - (size / 2))){
        if(x){
            if(leftData[ptr1].value.x < rightData[ptr2].value.x){
                combineData[ptr3] = leftData[ptr1];
                ptr1++;
            }
            else{
                combineData[ptr3] = rightData[ptr2];
                ptr2++;
            }
        }
        else{
            if(leftData[ptr1].value.y < rightData[ptr2].value.y){
                combineData[ptr3] = leftData[ptr1];
                ptr1++;
            }
            else{
                combineData[ptr3] = rightData[ptr2];
                ptr2++;
            }
        }
        ptr3++;
    }

    while(ptr1 < (size / 2)){
        combineData[ptr3] = leftData[ptr1];
        ptr1++;
        ptr3++;
    }

    while(ptr2 < (size - (size / 2))){
        combineData[ptr3] = rightData[ptr2];
        ptr2++;
        ptr3++;
    }

    for(int ind = 0; ind < size; ind++)
        data[ind] = combineData[ind];
}

long long getDistance(struct Point p1, struct Point p2){
    long long x1 = p1.x;
    long long x2 = p2.x;
    long long y1 = p1.y;
    long long y2 = p2.y;
    long long diffx = x1 - x2;
    long long diffy = y1 - y2;
    long long distance = (diffx * diffx) + (diffy * diffy);
    return distance;
}

long long minVal(long long val1, long long val2){
    if(val1 < val2)
        return val1;
    else
        return val2;
}

long long absolute(long long val1){
    if(val1 < 0)
        return (val1 * (-1ll));
    return val1;
}

struct Point* getClosestPairPoints(struct Data* datax, struct Data* datay, int size){

    if(size <= 1){
        struct Point* smallSpacePoints = (struct Point*)malloc(sizeof(struct Point) * 2);
        smallSpacePoints[0].x = 1e9+1;
        smallSpacePoints[0].y = 1e9+1;
        smallSpacePoints[1].x = -1e9-1;
        smallSpacePoints[1].y = -1e9-1;
        return smallSpacePoints;
    }

    int *augementing = (int*)malloc(sizeof(int) * size);
    for(int ind = 0; ind < size; ind++)
        augementing[ind] = -1;

    for(int ind = 0; ind < (size / 2); ind++)
        augementing[datax[ind].otherCoordInd] = 1;

    struct Data* leftDatax = (struct Data*)malloc(sizeof(struct Data) * (size / 2));
    for(int ind = 0; ind < (size / 2); ind++)
        leftDatax[ind] = datax[ind];

    struct Data* leftDatay = (struct Data*)malloc(sizeof(struct Data) * (size / 2));
    int ptrly = 0;
    for(int ind = 0; ind < size; ind++){
        if(augementing[ind] == 1){
            leftDatay[ptrly] = datay[ind];
            leftDatax[leftDatay[ptrly].otherCoordInd].otherCoordInd = ptrly;
            ptrly++;
        }
    }

    struct Data* rightDatax = (struct Data*)malloc(sizeof(struct Data) * (size - (size / 2)));
    for(int ind = size / 2; ind < size; ind++)
        rightDatax[ind - (size / 2)] = datax[ind];

    struct Data* rightDatay = (struct Data*)malloc(sizeof(struct Data) * (size - (size / 2)));
    int ptrry = 0;
    for(int ind = 0; ind < size; ind++){
        if(augementing[ind] == -1){
            rightDatay[ptrry] = datay[ind];
            rightDatay[ptrry].otherCoordInd -= (size / 2);
            rightDatax[rightDatay[ptrry].otherCoordInd].otherCoordInd = ptrry;
            ptrry++;
        }
    }

    struct Point* leftclosestPoints = getClosestPairPoints(leftDatax, leftDatay, size / 2);
    struct Point* rightclosestPoints = getClosestPairPoints(rightDatax, rightDatay, size - (size / 2));

    long long leftClosestDistance = getDistance(leftclosestPoints[0], leftclosestPoints[1]);
    long long rightClosestDistance = getDistance(rightclosestPoints[0], rightclosestPoints[1]);

    long long delta = minVal(leftClosestDistance, rightClosestDistance);

    long long middleX = leftDatax[(size / 2) - 1].value.x;
    long long subSetSize = 0;
    for(int ind = 0; ind < size; ind++){
        long long currX = datax[ind].value.x;
        if(absolute(currX - middleX) * absolute(currX - middleX) <= delta)
            subSetSize++;
    }

    struct Data* subSetPoints = (struct Data*)malloc(sizeof(struct Data) * subSetSize);
    int ptrss = 0;
    for(int ind = 0; ind < size; ind++){
        long long currX = datax[ind].value.x;
        if(absolute(currX - middleX) * absolute(currX - middleX) <= delta){
            subSetPoints[ptrss] = datax[ind];
            ptrss++;
        }
    }

    for(int ind = 0; ind < size; ind++)
        augementing[ind] = -1;

    for(int ind = 0; ind < subSetSize; ind++)
        augementing[subSetPoints[ind].otherCoordInd] = 1;

    struct Data* subSetPointsYsorted = (struct Data*)malloc(sizeof(struct Data) * subSetSize);
    int ptrssy = 0;
    for(int ind = 0; ind < size; ind++){
        if(augementing[ind] == 1){
            subSetPointsYsorted[ptrssy] = datay[ind];
            ptrssy++;
        }
    }

    long long minCrossDistance = LLONG_MAX;
    struct Point* crossPoints = (struct Point*)malloc(sizeof(struct Point) * 2);
    for(int ind = 0; ind < subSetSize; ind++){
        for(int ind2 = ind+1; ind2 <= minVal(ind + 15, subSetSize-1); ind2++){
            long long crossDistance = getDistance(subSetPointsYsorted[ind].value, subSetPointsYsorted[ind2].value);
            if(crossDistance < minCrossDistance){
                minCrossDistance = crossDistance;
                crossPoints[0] = subSetPointsYsorted[ind].value;
                crossPoints[1] = subSetPointsYsorted[ind2].value;
            }
        }
    }

    if(minCrossDistance < delta)
        return crossPoints;

    if(leftClosestDistance == delta)
        return leftclosestPoints;
    
    return rightclosestPoints;
}

long long getClosestPairDistance(struct Point *point, int n){
    if(n <= 1)
        return -1;

    struct Data *datax = (struct Data*)malloc(sizeof(struct Data) * n);
    struct Data *datay = (struct Data*)malloc(sizeof(struct Data) * n);
    for(int ind = 0; ind < n; ind++){
        datax[ind].value = point[ind];
        datax[ind].pointNo = ind;
        datay[ind].value = point[ind];
        datay[ind].pointNo = ind;
    }

    sortData(datax, n, 1);
    sortData(datay, n, 0);

    int *pointIndx = (int*)malloc(sizeof(int) * n);
    int *pointIndy = (int*)malloc(sizeof(int) * n);
    for(int ind = 0; ind < n; ind++){
        pointIndx[datax[ind].pointNo] = ind;
        pointIndy[datay[ind].pointNo] = ind;
    }

    for(int ind = 0; ind < n; ind++){
        datax[ind].otherCoordInd = pointIndy[datax[ind].pointNo];
        datay[ind].otherCoordInd = pointIndx[datay[ind].pointNo];
    }

    struct Point* closestPoints = getClosestPairPoints(datax, datay, n);
    long long closestDistance = getDistance(closestPoints[0], closestPoints[1]);
    return closestDistance;
}

int main(){

    int n;
    scanf("%d", &n);

    struct Point *points = (struct Point*)malloc(sizeof(struct Point) * n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        points[i].x = x;
        points[i].y = y;
    }

    long long closestDistance = getClosestPairDistance(points, n);
    printf("%lld \n", closestDistance);

    return 0;
}