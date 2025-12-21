#include <iostream>
#define MAX_SIZE 10

///< Задание 1 
void exer1(int N){
    
    int ar[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            ar[i][j] = (i)*N + j + 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            std::cout << ar[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

///< Задание 2
void exer2(int N){
    int ar[MAX_SIZE];
    std::cout << "Input " << N << " numbers" << std::endl;
    for(int i = 0; i < N; i++){
        std::cout << "Number " << i+1 << ": ";
        std::cin >> ar[i];
    }

    std::cout << "Result: ";
    for(int i = N-1; i >= 0; --i){
        std::cout << ar[i] << ' ';
    }
}

///< Задание 3
void exer3(int N){
    
    int ar[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            ar[i][j] = ((i+1) + (j+1) - 1) < N ? 0 : 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            std::cout << ar[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

///< Задание 4
void exer4(int N){
    
    int ar[MAX_SIZE][MAX_SIZE];
    int currentNum = 1;
    int top = 0, bottom = N - 1, right = N - 1, left = 0;

    while(currentNum <= N*N){
        ///< Идем по верхней строке 
        for(int i = left; i <= right; i++){
            ar[top][i] = currentNum++;
        }
        top++;

        ///< Идем по правому столбцу
        for(int i = top; i <= bottom; i++){
            ar[i][right] = currentNum++;
        }
        right--;

        ///< Идем по нижней строке
        for(int i = right; i >= left; i--){
            ar[bottom][i] = currentNum++;
        }
        bottom--;

        ///< Идем по левому столбцу
        for(int i = bottom; i >= top; i--){
            ar[i][left] = currentNum++;
        }
        left++;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            std::cout << ar[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main(){
    int N;
    do{
        std::cout << "Input size less than " << MAX_SIZE << ": ";
        std::cin >> N;
    }while(N > MAX_SIZE);

    exer1(N);
    exer2(N);
    exer3(N);
    exer4(N);
}

