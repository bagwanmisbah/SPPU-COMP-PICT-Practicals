#include <iostream>
#include <vector>
using namespace std;

class process
{
    int number; // number of processes
    int *pid;   // err for expression must have object-to-pointer type
    int *AT;
    int *BT;
    int *CT;
    int *TAT;
    int *WT;
    vector<int> executionOrder; // to keep track of execution order

public:
    // process() {}
    process(int n)
    {
        number = n;
        pid = new int[n];
        AT = new int[n];
        BT = new int[n];
        CT = new int[n];
        TAT = new int[n];
        WT = new int[n]; // since class variables are pointer, they are allocated memory dynamically
    }
    void get()
    {
        // ACCEPTING PID ,AT AND BT;
        for (int i = 0; i < number; i++)
        {
            cout << "Enter pid for " << i + 1 << "th process :" << endl;
            cin >> pid[i];
            cout << "Enter Arrival Time for " << i + 1 << "th process :" << endl;
            cin >> AT[i];
            cout << "Enter Burst Time for " << i + 1 << "th process :" << endl;
            cin >> BT[i];
        }
    }
    void display()
    {
        cout << "PID" << "\tAT" << "\tBT" << "\tCT" << "\tTAT" << "\tWT" << endl;
        for (int i = 0; i < number; i++)
        {
            cout << pid[i] << " \t" << AT[i] << "\t " << BT[i] << "\t " << CT[i] << "\t " << TAT[i] << "\t " << WT[i] << endl;
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
        int temp;
        for (int i = 0; i < number - 1; i++)
        {
            for (int j = 1; j < number - i - 1; j++)
            {
                if (AT[j] > AT[j + 1])
                {
                    swap(AT[j], AT[j + 1]);
                    swap(pid[j], pid[j + 1]);
                    swap(BT[j], BT[j + 1]);
                }
            }
        }
    }
    void fcfs()
    {
        CT[0] = AT[0] + BT[0]; // THE FIRST PROCESS COMPLETION TIME IN FCFS WILL BE THE SUM OF ARRIVAL AND BURST TIME
        executionOrder.push_back(0);
        for (int i = 1; i < number; i++)
        {
            if (CT[i - 1] > AT[i])
            {
                CT[i] = BT[i] + CT[i - 1];
                // completion time of current process is burst time of that process + completion time of previous process
                // process starts after previous process is completed
                // if completion time of previous process was greater than arrival time of current process
                // then it means current process arrived when previous one was still executing
                // since FCFS is a non-preemptive scheduling algorithm ,
                // it waits for previous process to complete executing and only after that it starts execution of the next process
            }
            else
            {
                // if process arrived when the previous process was done executing then we can carry out its execution with FCFS
                CT[i] = BT[i] + AT[i];
            }
            // now for each process we calculate WAITING AND TURNAROUND TIME individually
            //  WT[i]=CT[i]-BT[i];
            //  TAT[i]=WT[i]+BT[i];//wromg
            executionOrder.push_back(i);
        }
        for (int i = 0; i < number; i++)
        {
            TAT[i] = CT[i] - AT[i];
        }
        for (int i = 0; i < number; i++)
        {
            WT[i] = TAT[i] - BT[i];
        }
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
    process p(4);
    p.get();
    p.sort();
    p.fcfs();
    p.display();
    p.calculateAverage();
    p.displayExecutionOrder(); // display the order of processes

    // sending processes to function to sort themselves according to arrival time
    // sort(p, number);

  //tc
  //1 0 5
  //2 1 3
  //3 2 8
  //4 3 6

    return 0;
}
