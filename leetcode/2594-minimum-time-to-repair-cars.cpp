/*
 * 2594. Minimum Time to Repair Cars
 * Difficulty: Medium
 * 
 * You are given an integer array ranks representing the
ranks
ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
Return the
minimum
minimum time taken to repair all the cars.
Note:
Note: All the mechanics can repair the cars simultaneously.

**Example 1:**

**Example 1:**
Input: ranks = [4,2,3,1], cars = 10
Output: 16

Explanation:
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

**Example 2:**

**Example 2:**
Input: ranks = [5,1,8], cars = 6
Output: 16

Explanation:
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

**Constraints:**

**Constraints:**
1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106
 */

        }
    }
    return minI;
}
int intMaxArr(vector<long long> arr){
    int minI=0;
    for (int i=1;i<arr.size();i++){
        if (arr.at(i)>arr.at(minI)){
            minI=i;
        }
    }
    return minI;
}

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            // sort(ranks.begin(),ranks.end());
            vector<long long> ncars = vector<long long>();
            vector<long long>costs = vector<long long>();
            priority_queue<pair<long long,long long>,vector<pair<long long,
long long>>,greater<pair<long long,long long>>> pq;
            for (int car=0;car<ranks.size();car++){
                ncars.push_back(0);
                costs.push_back(0);
                pq.push({ranks[car],car});
            }
            while (cars>0){
                long long minI = pq.top().second;pq.pop();
                ncars[minI] = ncars[minI]+1;
                costs[minI] = (long long) ranks[minI]*(ncars[minI]*ncars
[minI]);
                // Nextcosts[minI] = ranks[minI]*pow(1+ncars[minI],2);
                pq.push({ranks[minI]*pow(1+ncars[minI],2),minI});
                cars--;
            }
            long long toRet=costs[intMaxArr(costs)];
            return toRet;
        }
    };
