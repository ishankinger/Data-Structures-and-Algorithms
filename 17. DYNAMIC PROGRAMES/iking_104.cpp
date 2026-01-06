// NINJA'S TRAINING

#include<bits/stdc++.h>
using namespace std;

int f(int day, int last, vector< vector<int> > tasks){
    int maxi = 0;

    if(day == 0){
        for(int i = 0; i < 3; i++){
            if(i != last) maxi = max(maxi,tasks[0][i]);
        }
        return maxi;
    }

    for(int i = 0; i < 3; i++){
        int points = 0;
        if(i != last){
            points = tasks[day][i] + f(day-1,i,tasks);
        }
        maxi = max(points,maxi);
    }
    return maxi;
}

int f_memo(int day, int last, vector< vector<int> > tasks, vector< vector<int> > &dp){
    int maxi = 0;

    if(dp[day][last] != -1) return dp[day][last];

    if(day == 0){
        for(int i = 0; i < 3; i++){
            if(i != last) maxi = max(maxi,tasks[0][i]);
        }
        return dp[day][last] = maxi;
    }

    for(int i = 0; i < 3; i++){
        int points = 0;
        if(i != last){
            points = tasks[day][i] + f_memo(day-1,i,tasks,dp);
        }
        maxi = max(points,maxi);
    }

    return dp[day][last] = maxi;
}

int f_tab(int days, vector< vector<int> > points){
    vector< vector<int> > dp(days,vector<int>(4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    for(int day = 1; day < days; day++){
        for(int last = 0; last < 4; last++){
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[days-1][3]; 
}

int f_tab_so(int days, vector< vector<int> > points){
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < days; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
        temp[last] = 0;
        for (int task = 0; task <= 2; task++) {
            if (task != last) {
            temp[last] = max(temp[last], points[day][task] + prev[task]);
            }
        }
        }
        prev = temp;
    }
    return prev[3];
}

int ninjaTraining(int days, vector< vector<int> > tasks){
    vector< vector<int> > dp(days,vector<int>(4,-1));
    return f_memo(days-1,3,tasks,dp);
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > tasks(n,vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> tasks[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cout << tasks[i][j] << " ";
        }
        cout << "\n";
    }

    cout << f(n-1,3,tasks) << "\n";
    cout << ninjaTraining(n,tasks) << "\n";
    cout << f_tab(n,tasks) << "\n";
    cout << f_tab_so(n,tasks) << "\n";

    return 0;
}