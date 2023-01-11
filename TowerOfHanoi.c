#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int stack1, int buffer, int stack2, int disks){
	if(disks==1){
        printf("Move disk %d from %d to %d\n", disks, stack1, stack2);
		// cout<<"Move disk "<<disks<<" from "<<stack1<<" to "<<stack2<<endl;
		return;
	}
	towerOfHanoi(stack1, stack2, buffer, disks-1);
    printf("Move disk %d from %d to %d\n", disks, stack1, stack2);
	// cout<<"Move disk "<<disks<<" from "<<stack1<<" to "<<stack2<<endl;
	towerOfHanoi(buffer, stack1, stack2, disks-1);
}

int main(){
    towerOfHanoi(1, 2, 3, 3);
    return 0;
}