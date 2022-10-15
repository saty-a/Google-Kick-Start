#include <bits/stdc++.h>
using namespace std;


int circle(int x1, int y1, int r1, int r2)
{
    // calculating distance between (x1, y1) and origin(0,0)
    int d = ( x1*x1 +  y1*y1 );
    // square of distance
    if(d > (r1+r2)*1ll*(r1+r2) ){   //checking whether the stone(disc) touches the house
        return -1;
    }
    else if(d<= (r1 + r2)*1ll*(r1 + r2) ){
        return d;
    }
}

int main()
{
    int t; cin>>t;
    int caseN = 1;
    while(t--){
        int stoneRadius, houseRadius;
        cin>>stoneRadius>>houseRadius;

        int redScore = 0 , yellowScore = 0;

        vector <int> vRed, vYellow;

        int  n; cin>>n;
        for(int i=0; i<n; i++){
            int q1, q2;
            cin>>q1>>q2;
            int check = circle(q1, q2, stoneRadius, houseRadius); 
            if(check != -1){    // check decides whether stone touches the house or in the house
                vRed.push_back(check);
                //if stone disc satisfies the condition then vRed will store the distance between them
            }
        }


        int  m; cin>>m;
        for(int i=0; i<m; i++){
            int q1, q2;
            cin>>q1>>q2;
            int check = circle(q1, q2, stoneRadius, houseRadius);
            if(check != -1){ // check decides whether stone touches the house or in the house
                vYellow.push_back(check);
                //if stone disc satisfies the condition then vRed will store the distance between them
            }
        }

        sort(vRed.begin(), vRed.end());
        sort(vYellow.begin(), vYellow.end());
        // sorting help us to search the minimal values in the two vectors easily


        if(vRed.size()==0){ // this means no red stone is closer to house
            yellowScore = vYellow.size();
        }
        else if(vYellow.size()==0){ //this means no yellow stone is closer to house
            redScore = vRed.size();
        }
        else if(vRed[0]<vYellow[0]){// when first red stone is closer to house than any yellow stone
            
            // answer will be the total number of red stone that are closer than the first yellow stone
            for(int i=0; i<vRed.size(); i++){ 
                if(vRed[i]<vYellow[0]){
                redScore++;
                }
            }
        }
        else if(vYellow[0]<vRed[0]){ // when first yellow stone is closer to house than any red stone
            
            // answer will be the total number of yellow stone that are closer than the first red stone
            for(int i=0; i<vYellow.size(); i++){                    
                if(vYellow[i]<vRed[0]){
                    yellowScore++;
                }
            }
        }
        
        cout<<"Case #"<<caseN<<": "<< redScore<<" "<<yellowScore<<endl; caseN++;



    }
}