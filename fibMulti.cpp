#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

std::vector<float> resultMultiThread = {0,1,1,2,3,5};

// Function to calculate Fibonacci(single-threaded)
int fibonacciSingleThread(unsigned int start, unsigned int end) {
    if (end < 5) {
      return 0;
    }
    for(int i = start +6 ; i <= end; i = i + 3 )
    {
       resultMultiThread[i] = (4 * resultMultiThread[i-3] + resultMultiThread[i-6]);
       
       //std::cout << resultMultiThread[i] << " "<< resultMultiThread[i-1] << std::endl;
    }
    return 1;
}

// Function to calculate Fibonacci(multi-threaded)
void fibonacciMultiThread(unsigned int start, unsigned int end, int threadNum) {

    std::vector<std::thread> threads;
    for (int i = 0; i < threadNum; i++) {
        threads.emplace_back(fibonacciSingleThread, start + i, end + i);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}



int main() {
    unsigned int n;  
    const int threadNum = 3;

    std::cout << "Enter Fib number :";
    std::cin >> n;

   resultMultiThread.resize(n+1 , -1);
    
    auto startMultiThread = std::chrono::system_clock::now();
    fibonacciMultiThread(0, n, threadNum);
    auto endMultiThread = std::chrono::system_clock::now();

    for(int i=0; i < n+1; i++)
    {
        std::cout << resultMultiThread[i] << std::endl;
    }

    // Calculate execution times
    
    std::chrono::duration<double> durationMultiThread = (endMultiThread - startMultiThread);

    
    std::cout << "Multi-threaded Fibonacci took: " << durationMultiThread.count() << " milliseconds" << std::endl;

    return 0;
}