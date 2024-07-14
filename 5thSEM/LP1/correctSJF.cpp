#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class process
{
public:
    int *pid;
    int *AT;
    int *BT;
    int *CT;
    int *RT; // Remaining Time
    int *TAT;
    int size;
    int *WT;
    vector<int> order;
    process() {}
    process(int n)
    {
        size = n;
        pid = new int[n];
        AT = new int[n];
        BT = new int[n];
        CT = new int[n];
        RT = new int[n];
        TAT = new int[n];
        WT = new int[n];
    }

    void get()
    {
        // Accepting PID, AT, and BT;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter pid for " << i + 1 << "th process :" << endl;
            cin >> pid[i];
            cout << "Enter Arrival Time for " << i + 1 << "th process :" << endl;
            cin >> AT[i];
            cout << "Enter Burst Time for " << i + 1 << "th process :" << endl;
            cin >> BT[i];
            RT[i] = BT[i]; // Initial remaining time is the burst time
        }
    }

    void display()
    {
        cout << "PID" << "\tAT" << "\tBT" << "\tCT" << "\tTAT" << "\tWT" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << pid[i] << " \t" << AT[i] << "\t " << BT[i] << "\t " << CT[i] << "\t " << TAT[i] << "\t " << WT[i] << endl;
        }
    }

    void sort()
    {
        // Sorting according to Arrival Time
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (AT[j] > AT[j + 1])
                {
                    swap(pid[j], pid[j + 1]);
                    swap(AT[j], AT[j + 1]);
                    swap(BT[j], BT[j + 1]);
                    swap(RT[j], RT[j + 1]);
                }
            }
        }
    }

    void sjf_preemptive()
    {
        int complete = 0, time = 0, minm = INT_MAX;
        int shortest = -1, finish_time;
        bool check = false;

        while (complete != size)
        {
            // Find process with minimum remaining time at each time unit
            for (int j = 0; j < size; j++)
            {
                if ((AT[j] <= time) && (RT[j] < minm) && RT[j] > 0)
                {
                    minm = RT[j];
                    shortest = j;
                    check = true;
                }
            }

            if (check == false)
            {
                time++;
                continue;
            }

            // Add the process PID to the order only if it's the first time it is selected or if it's a different process
            if (order.empty() || order.back() != pid[shortest])
            {
                order.push_back(pid[shortest]);
            }

            RT[shortest]--;
            minm = RT[shortest];
            if (minm == 0)
                minm = INT_MAX;

            if (RT[shortest] == 0)
            {
                complete++;
                check = false;

                finish_time = time + 1;
                CT[shortest] = finish_time;
                TAT[shortest] = CT[shortest] - AT[shortest];
                WT[shortest] = TAT[shortest] - BT[shortest];
            }
            time++;
        }
    }

    void displayOrder()
    {
        cout << "Order of execution:" << endl;
        for (int i = 0; i < order.size(); i++)
        {
            cout << order[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    process p(6);
    p.get();
    p.sort();
    p.sjf_preemptive();
    p.display();
    p.displayOrder();

    return 0;
}
