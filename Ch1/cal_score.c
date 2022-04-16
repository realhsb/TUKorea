#define MAX_ELEMENT 100
int score[MAX_ELEMENT];         //자료구조

int get_max_score(int n){           //학생 수 n
    int i, largest; 
    largest = score[0];
    for(i = 1; i < n; i++){
        if(score[i] > largest){
            largest = score[i];         //알고리즘
        }
    }
    return largest;
}