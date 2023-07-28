#include<stdio.h>
#include<iostream>
using namespace std;
int ct[10];

void findWaitingTime(int processes[], int n,int at[],
						int bt[], int wt[])
{
	
	wt[0] = 0;
    ct[0]=at[0]+bt[0];

	for (int i = 1; i < n ; i++ ){
        ct[i]=ct[i-1]+bt[i];
        wt[i]=ct[i-1]-at[i];
     }
		
}


void findTurnAroundTime( int processes[], int n,int at[],
				int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime( int processes[], int n,int at[], int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0,total_ct=0;


	findWaitingTime(processes, n, at,bt, wt);

	
	findTurnAroundTime(processes, n,at, bt, wt, tat);

	
	cout<< "Pr "<<"\t"<<"AT"<<"\t"<< " BT "
		<<"\t"<< " WT" <<"\t"<< "CT" <<"\t"<< " TAT\n";

	
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
        total_ct=total_ct+ ct[i];
        cout << " " << processes[i]<<"\t"<< at[i] <<"\t"<< bt[i] 
			<<"\t"<< wt[i] << "\t"<<ct[i] <<"\t"<< tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
    cout<<"\n Throughput ="<< (float)n/ct[n-1];  
}

int main()
{
	
	int processes[10];
	int n ;
    int AT[10];
    int burst_time[10];
    int temp;
    cout<<"Enter the no.of processes";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the process";
        cin>>processes[i];
        cout<<"Enter the Arrival time";
        cin>>AT[i];
        cout<<"Enter the burst time";
        cin>>burst_time[i];
    }
    for(int j=0;j<n-1;j++){
        for(int k=0;k<n-j-1;k++){
            if(AT[k]>AT[k+1]){
                temp= processes[k];
                processes[k]=processes[k+1];
                processes[k+1]=temp;

                temp=AT[k];
                AT[k]=AT[k+1];
                AT[k+1]=temp;
                temp=burst_time[k];
                burst_time[k]=burst_time[k+1];
                burst_time[k+1]=temp;
            }
        }
    }
	findavgTime(processes, n,AT, burst_time);
	return 0;
}

