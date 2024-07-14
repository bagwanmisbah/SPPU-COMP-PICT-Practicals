#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class process
{
public:
    int number; // number of processes
    int *pid;   // err for expression must have object-to-pointer type

    int *AT;
    int *BT;
    int *CT;
    int *RT;
    int *TAT;
    int *WT;
    int *priority;
    vector<int> executionOrder; // Single vector to store execution order
    int quantum;                // Time quantum for Round Robin

    process(int n)
    {
        number = n;
        pid = new int[n];
        AT = new int[n];
        BT = new int[n];
        CT = new int[n];
        RT = new int[n];
        TAT = new int[n];
        WT = new int[n];
        priority = new int[n];
    }

    void get()
    {
        // Accepting PID, AT, BT and priority
        for (int i = 0; i < number; i++)
        {
            cout << "Enter pid for " << i + 1 << "th process :" << endl;
            cin >> pid[i];
            cout << "Enter Arrival Time for " << i + 1 << "th process :" << endl;
            cin >> AT[i];
            cout << "Enter Burst Time for " << i + 1 << "th process :" << endl;
            cin >> BT[i];
            cout << "Enter Priority for " << i + 1 << "th process (lower number means higher priority):" << endl;
            cin >> priority[i];
            RT[i] = BT[i]; // Initial remaining time is the burst time
        }
    }

    void display()
    {
        cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < number; i++)
        {
            cout << pid[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
        }
    }

    void displayExecutionOrder()
    {
        cout << "Execution Order of Processes:" << endl;
        for (int i = 0; i < executionOrder.size(); i++)
        {
            cout << "Process " << executionOrder[i] + 1 << " (PID: " << pid[executionOrder[i]] << ")" << endl;
        }
    }

    void sort()
    {
        // Sorting according to Arrival Time
        for (int i = 0; i < number - 1; i++)
        {
            for (int j = 0; j < number - i - 1; j++)
            {
                if (AT[j] > AT[j + 1])
                {
                    swap(pid[j], pid[j + 1]);
                    swap(AT[j], AT[j + 1]);
                    swap(BT[j], BT[j + 1]);
                    swap(RT[j], RT[j + 1]);
                    swap(priority[j], priority[j + 1]);
                }
            }
        }
    }

    void fcfs()
    {
        executionOrder.clear(); // Clear previous execution order
        CT[0] = AT[0] + BT[0];  // The first process completion time in FCFS will be the sum of arrival and burst time
        executionOrder.push_back(0);
        for (int i = 1; i < number; i++)
        {
            if (CT[i - 1] > AT[i])
            {
                CT[i] = BT[i] + CT[i - 1];
                // completion time of current process is burst time of that process + completion time of previous process
                // process starts after previous process is completed
                // if completion time of previous process was greater than arrival time of current process
                // than it means current process arrived when previous one was still executing
                // since FCFS is a non-preemptive scheduling algorithm ,
                // it waits for previous process to complete executing and only after that it starts execution of the next process
            }
            else
            {
                CT[i] = BT[i] + AT[i];
            }
            executionOrder.push_back(i);
        }
        // now for each process we calculate WAITING AND TURNAROUND TIME individually
        //  WT[i]=CT[i]-BT[i];
        //  TAT[i]=WT[i]+BT[i];//wromg
        for (int i = 0; i < number; i++)
        {
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];
        }
    }

    void sjf_preemptive()
    {
        executionOrder.clear(); // Clear previous execution order
        int complete = 0, time = 0, minm = INT_MAX;
        int shortest = -1, finish_time;
        bool check = false;

        while (complete != number)
        {
            // Find process with minimum remaining time at each time unit
            for (int j = 0; j < number; j++)
            {
                if ((AT[j] <= time) && (RT[j] < minm) && RT[j] > 0)
                {
                    minm = RT[j];
                    shortest = j;
                    check = true;
                }
            }

            if (!check)
            {
                time++;
                continue;
            }

            // Add the process PID to the order only if it's the first time it is selected or if it's a different process
            if (executionOrder.empty() || executionOrder.back() != shortest)
            {
                executionOrder.push_back(shortest);
            }

            RT[shortest]--;
            minm = RT[shortest] ? RT[shortest] : INT_MAX;

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

    void priorityScheduling()
    {
        executionOrder.clear(); // Clear previous execution order
        vector<bool> isCompleted(number, false);
        int complete = 0, time = 0;

        while (complete != number)
        {
            int highestPriority = INT_MAX;
            int selectedProcess = -1;

            for (int i = 0; i < number; i++)
            {
                if ((AT[i] <= time) && !isCompleted[i] && (priority[i] < highestPriority))
                {
                    highestPriority = priority[i];
                    selectedProcess = i;
                }
            }

            if (selectedProcess == -1)
            {
                time++;
                continue;
            }

            // If a process is selected
            time += BT[selectedProcess];
            CT[selectedProcess] = time;
            TAT[selectedProcess] = CT[selectedProcess] - AT[selectedProcess];
            WT[selectedProcess] = TAT[selectedProcess] - BT[selectedProcess];
            isCompleted[selectedProcess] = true;
            executionOrder.push_back(selectedProcess);
            complete++;
        }
    }

    void roundRobin()
    {
        executionOrder.clear(); // Clear previous execution order
        int time = 0, complete = 0;
        int *remainingBT = new int[number];
        for (int i = 0; i < number; i++)
        {
            remainingBT[i] = BT[i];
        }

        while (complete != number)
        {
            bool done = true;
            for (int i = 0; i < number; i++)
            {
                if (remainingBT[i] > 0)
                {
                    done = false;
                    if (remainingBT[i] > quantum)
                    {
                        time += quantum;
                        remainingBT[i] -= quantum;
                    }
                    else
                    {
                        time += remainingBT[i];
                        CT[i] = time;
                        TAT[i] = CT[i] - AT[i];
                        WT[i] = TAT[i] - BT[i];
                        remainingBT[i] = 0;
                        complete++;
                    }
                    executionOrder.push_back(i);
                }
            }
            if (done)
                break;
        }

        delete[] remainingBT;
    }

    void calculateAverage()
    {
        int totalWT = 0;
        int totalTAT = 0;
        for (int i = 0; i < number; i++)
        {
            totalTAT += TAT[i];
            totalWT += WT[i];
        }
        cout << "Average Turnaround Time: " << (double)totalTAT / number << endl;
        cout << "Average Waiting Time: " << (double)totalWT / number << endl;
        // int avgWT = 0;
        // int avgTAT = 0;
        // for (int i = 0; i < number; i++)
        // {
        //     avgTAT = avgTAT + TAT[i];
        //     avgWT = avgWT + WT[i];
        // }
        // cout << avgTAT << endl;
        // cout << avgWT << endl;

        // cout << "Average time required to execute " << number << "processes : " << avg << "ms" << endl;
    }
};

int main()
{
    int choice, n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    process p(n);
    p.get();
    // sending processes to function to sort themselves according to arrival time
    // sort(p, number);

    cout << "Enter the time quantum for Round Robin scheduling: ";
    cin >> quantum;
    p.quantum = quantum;

    do
    {
        cout << "\nChoose the scheduling algorithm:\n";
        cout << "1. First Come First Serve (FCFS)\n";
        cout << "2. Shortest Job First (Preemptive)\n";
        cout << "3. Priority Scheduling (Non-Preemptive)\n";
        cout << "4. Round Robin (Preemptive)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.sort();
            p.fcfs();
            p.display();
            p.calculateAverage();
            p.displayExecutionOrder();
            break;
        case 2:
            p.sort();
            p.sjf_preemptive();
            p.display();
            p.calculateAverage();
            p.displayExecutionOrder();
            break;
        case 3:
            p.sort();
            p.priorityScheduling();
            p.display();
            p.calculateAverage();
            p.displayExecutionOrder();
            break;
        case 4:
            p.sort();
            p.roundRobin();
            p.display();
            p.calculateAverage();
            p.displayExecutionOrder();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 5);

    return 0;
}
