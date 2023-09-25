// MAKING A VECTOR AND THEN PRINTING IT AND APPLY OPERATIONS ON IT

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;                               // A VECTOR CAN BE USED AS A VARIABLE DEFINED HERE AND VALUE INSERTED LATER
    v={8,4,7,1,3};                              // ANOTHER WAY TO DEFINE A VECTOR ( CAN ALSO DEFINE FOR VI AND VIK )
    
    vector<int> v_c = v;                        // SIMPLY WE CAN COPY ALL THE ELEMENTS OF ONE VECTOR TO ANOTHER VECTOR
    v_c.push_back(5);                           // TIME COMPLEXITY IS O(N)
    v_c.push_back(6);

    // ******* IF WE USE AMPERSANT OPERATOR HERE THEN THERE WILL BE SAME CHANGES OCCUR IN V_C **********
    vector<int> &v_p=v;                         // SIMPLE TO VARIABLE HERE ALSO SAME LOCATION BOTH WILL BE PRESENT SO SAME CHANGES WILL 
    v_p.push_back(1);                           // OCCUR TO BOTH SIMUTANEOUSLY
    v_p.push_back(2);

    for(int i=0;i<v.size();i++){                // LOOP TO PRINT THE ELEMENTS OF THE VECTORS
        cout<<v[i]<<" ";                        // V[INDEX OF THE ELEMENT] WILL GIVE THE RESPECTIVE ELEMENT AT THAT PARTICUALAR INDEX
    }
    cout<<endl;
    for(int i=0;i<v_c.size();i++){
        cout<<v_c[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<v_p.size();i++){
        cout<<v_p[i]<<" ";
    }
    cout<<"\n";

    vector<int>vi(5);                           // IF WE HAVE V(SIZE) THEN ADDITON OCCUR OTHER THAN THAT MEANS SIZE WILL HAVE ZERO
    cout<<vi[0]<<"\n";
    vector<int>vik(5,1);                        // V(SIZE,INIT VALUE) SO A VECTOR OF SIZE 5 WILL BE FORMED WITH EACH VALUE IN IT AS 1

    for(int i=0;i<vi.size();i++){               // THIS SHOWS THAT IF WE INITIALLY TAKE SIZE THEN IF WE PRINT THEN THEY WILL HAVE
        cout<<vi[i]<<" ";                       // ZEROES IN IT AND THEY WILL BE PRINTED
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<vik[i]<<" ";
    }
    cout<<endl;

    cout<<v[2]<<endl;                           // SO WE CAN GET ANY ELEMENT OF THE VECTOR SIMPLY
                                                // NOT TO USE DOT BETWEEN NAME AND SQUARE BRACKETS
    v.insert(v.begin()+1,6);                    // v.begin()+ INDEX WILL GIVE US Ith ELEMENT AND WE HAVE TO ADD AT THAT PLACE THIS    
                                                // SIMILAR TO THIS WE HAVE v.end() WHICH CAN ALSO BE USED
    for(int i=0;i<v.size();i++){                 
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+2);
    v.erase(v.end()-2);                         // TO DELETE ANY ELEMENT FROM Ith INDEX FROM THE BACK
                                                // MEANS SECOND ELEMENT FROM LAST WILL BE DELETED
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    v.clear();                                  // THIS WILL DELETE ALL THE ELEMENTS FROM THE VECTORS

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl;
    }
    cout<<endl;

    vik.assign(3,2);                            // THIS MEANS FIRST 3 VALUES ARE ASSIGNED TO BE 2 IN THE GIVEN VECTOR
    
    for(int i=0;i<5;i++){
        cout<<vik[i]<<" ";
    }
    cout<<endl;
}