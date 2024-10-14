#include <bits/stdc++.h>
using namespace std;

int fifo(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> q;

    int miss = 0; 
    for (int i = 0; i < n; i++) {
        
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]); 
                q.push(pages[i]); 
                miss++;
                cout << "Page Miss: " << pages[i] << " - Frame: ";
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int val = q.front(); 
                q.pop(); 
                s.erase(val); 
                s.insert(pages[i]);
                q.push(pages[i]); 
                miss++;
                cout << "Page Miss: " << pages[i] << " - Frame: ";
            } else {
                cout << "Page Hit: " << pages[i] << " - Frame: ";
            }
        }

        // Print the current state of the queue
        vector<int> tempQueue;
        while (!q.empty()) {
            tempQueue.push_back(q.front());
            q.pop();
        }
        
        for (int j : tempQueue) {
            cout << j << " ";
            q.push(j);
        }
        cout << endl; 
    }

    return miss;
}

int LRU(int pages[], int n, int capacity) {
    deque<int> q; 
    int miss = 0; 

    for (int i = 0; i < n; i++) {
        auto itr = find(q.begin(), q.end(), pages[i]); // Find if page is in LRU queue
        if (itr == q.end()) { 
            miss++; 
            if (q.size() == capacity) { 
                q.pop_front();
            }
            q.push_back(pages[i]);
            cout << "Page Miss: " << pages[i] << " - Frame: ";
        } else { 
            q.erase(itr);
            q.push_back(pages[i]);
            cout << "Page Hit: " << pages[i] << " - Frame: ";
        }

        for (int page : q) {
            cout << page << " ";
        }
        cout << endl;
    } 
    return miss; 
}

bool search(int key, vector<int>& fr){
    for(int i=0;i<fr.size();i++)
    {
        if(fr[i] == key)
        return true;
    }
    return false;
}

int predict(int pages[], vector<int>&fr, int pn, int index){
    int res =-1, farthest = index;
    for(int i=0;i<fr.size();i++){
        int j;
        for(j=index;j<pn;j++){
            if(fr[i] == pages[j]){
                if(j> farthest){
                    farthest = j;
                    res = i;
                }
                break;
            }   
        }
        if(j == pn){
        return i;
        }
    }

    return (res == -1) ? 0 :res;
    
}

int optimalPage(int pages[], int pn, int fn) {
    vector<int> fr;
    int hit = 0; 

    for (int i = 0; i < pn; i++) {
        if (search(pages[i], fr)) {
            hit++;
            cout << "Page Hit: " << pages[i] << " - Frame: ";
        } else {
            cout << "Page Miss: " << pages[i] << " - Frame: ";
            if (fr.size() < fn) {
                fr.push_back(pages[i]);
            } else {
                int j = predict(pages, fr, pn, i + 1);
                fr[j] = pages[i]; 
            }
        }

        for (int page : fr) {
            cout << page << " ";
        }
        cout << endl;
    }

    return hit;
}

int main(){
    int pn,fn,c,flag=1;
    cout<<"Enter Number of Pages: ";
    cin>>pn;
    int pages[pn];
    for(int i=0;i<pn;i++){
        cout<<"Enter page number: ";
        cin>>pages[i];
    }

    cout<<"Enter frame size: ";
    cin>>fn;


    int hit,miss;
    float hr;

    while (flag)
    {
        cout<<"Enter algorithm choice:\n1. FIFO \n2. LRU \n3. Optimal\nEnter choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
             miss = fifo(pages, pn, fn);
             hit = pn - miss;
            cout<<"Hits: "<<hit<<"\nMisses: "<<miss<<endl;
             hr = hit;hr/=pn;
            cout<<"Hit Ratio: "<<hr<<endl;
            cout<<"Do you want to continue(1/0): ";
            cin>>flag;
            break;

        case 2:
             miss = LRU(pages, pn, fn);
             hit = pn - miss;
            cout<<"Hits: "<<hit<<"\nMisses: "<<miss<<endl;
             hr = hit;hr/=pn;
            cout<<"Hit Ratio: "<<hr<<endl;
            cout<<"Do you want to continue(1/0): ";
            cin>>flag;
            break;

        case 3:
             hit = optimalPage(pages,pn,fn);
             miss = pn - hit;
            cout<<"Hits: "<<hit<<"\nMisses: "<<miss<<endl;
             hr = hit;hr/=pn;
            cout<<"Hit Ratio: "<<hr<<endl;
            cout<<"Do you want to continue(1/0): ";
            cin>>flag;
            break;
        
        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    
    return 0;
}
