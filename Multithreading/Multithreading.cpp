#include <thread>
#include <iostream>

using namespace std;

bool ShouldEndThread = false;

int ThreadVar = 0;

void HelloWorldThread ()
{
    while (!ShouldEndThread)
    {
        ThreadVar++;
        if (ThreadVar > 1000)
        {
            ThreadVar = 0;
        }
    }
}

int main()
{
    cout << "hello world" << endl;
    char UserInput;
    std::thread Hello(HelloWorldThread);
    bool DidQuit = false;

    while (1)
    {
        cout << "enter any key except space to stop counter" << endl;
        cout << "q to quit" << endl;
        cin >> UserInput;
        DidQuit = (UserInput == 'q');
        cout << "ThreadVar:" << ThreadVar << endl;
    }

    Hello.join();

    return 0;
}