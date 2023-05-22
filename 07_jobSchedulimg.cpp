#include<bits/stdc++.h>
using namespace std;

void jobScheduling(priority_queue<pair<int, pair<int,int>>> &q, vector<bool> &done){

    int min_days = 0;
    int max_profit = 0;

    while( !q.empty() ){
       
       auto top = q.top();
       q.pop();

       int curr_profit = top.first;
       int curr_id = top.second.first;
       int curr_deadline = top.second.second;

        if(!done[curr_deadline]){
            done[curr_deadline] = true;
            min_days++;
            max_profit += curr_profit;
            
        }
        else{
            for(int i = curr_deadline - 1; i >= 0; i--){
                if(!done[i]){
                    done[i] = true;
                    min_days++;
                    max_profit += curr_profit;
                }
            }
        }
    }   

    cout << "\n";
    cout << min_days << " " << max_profit << "\n";
}

int main(){
    int jobs;
    cout << "Enter number of jobs : ";
    cin >> jobs ;

    priority_queue<pair<int, pair<int,int>>> q;
    int maxi = INT_MIN;
    
    cout << "Enter id deadline and profit : " <<endl;
    for(int i = 1; i <= jobs; i++)
    {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;

        if(deadline > maxi) maxi = deadline;
        q.push({profit,{id,deadline}});
    }

    vector<bool> done(maxi+1, false);
    done[0] = true;

    jobScheduling(q,done);

 return 0;
 }