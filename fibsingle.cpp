#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
std::vector<float> resultSingleThread = {0,1};

// Function to calculate Fibonacci(single-threaded)
int fibonacciSingleThread(unsigned int end) {
    if (end == 0) {
        return 0;
    } else if (end == 1) {
        return 1;
    }
    for(int i = 2; i <= end; i++)
    {
       resultSingleThread[i] = (resultSingleThread[i-1] + resultSingleThread[i-2]);
       
       std::cout << resultSingleThread[i] << " "<< resultSingleThread[i-1] << std::endl;
    }
    return 1;
}

int main() {
    unsigned int n;  
    std::cout << "Enter Fib number :";
    std::cin >> n;

    resultSingleThread.resize(n+1 , -1);

    
    auto startSingleThread = std::chrono::system_clock::now();
    fibonacciSingleThread(n);
    auto endSingleThread = std::chrono::system_clock::now();

    for(int i=0; i < n+1; i++)
    {
        std::cout << resultSingleThread[i] << " " << std::endl;
    }

    // Calculate execution times
    std::chrono::duration<double> durationSingleThread = (endSingleThread - startSingleThread);


    std::cout << "Single-threaded Fibonacci took: " << durationSingleThread.count() << " milliseconds" << std::endl;
  
}