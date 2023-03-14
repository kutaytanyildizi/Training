#include <iostream>
#include <list>

// Observer is a behavioral design pattern that lets you define a subscription mechanism to notify
// multiple objects about any events that happen to the object they’re observing.

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string &messageFromSubject) = 0;
};

class ISubject
{
public:
    virtual ~ISubject() = default;
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject
{
private:
    std::list<IObserver *> observerList;
    std::string message;

public:
    ~Subject() override
    {
        std::cout << "Subject destructor." << std::endl;
    }
    void Attach(IObserver *observer) override
    {
        observerList.push_back((observer));
    }
    void Detach(IObserver *observer) override
    {
        observerList.remove(observer);
    }
    void Notify() override
    {
        auto it = observerList.begin();
        HowManyObservers();
        while(it != observerList.end())
        {
            (*it)->Update(message);
            it++;
        }
    }
    void CreateMessage(std::string message = "Empty")
    {
        this->message = message;
        Notify();
    }
    void HowManyObservers()
    {
        std::cout << "There are " << observerList.size() << " observers in the list." << std::endl;
    }
};

class Observer : public IObserver
{
private:
    std::string messageFromSubject;
    Subject &subject;
    static int staticNumber;
    int number;

public:
    Observer(Subject &subject1) : subject(subject1)
    {
        this->subject.Attach(this);
        std::cout << "Observer constructor " << ++Observer::staticNumber << "\".\n";
        this->number = Observer::staticNumber;
    }
    virtual ~Observer()
    {
        std::cout << "Observer destructor \"" << this->number << "\".\n";
    }
    void Update(const std::string &messageFromSubject) override
    {
        this->messageFromSubject = messageFromSubject;
        PrintInfo();
    }
    void PrintInfo()
    {
        std::cout << "Observer \"" << number << "\": a new message is available --> " << this->messageFromSubject << std::endl;
    }
    void RemoveFromList()
    {
        subject.Detach(this);
        std::cout << "Observer \"" << this->number << "\" removed from the list." << std::endl;
    }
};

int Observer::staticNumber = 0;

int main()
{
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("Hello World :D");
    observer3->RemoveFromList();

    subject->CreateMessage("The weather is hot today.");
    observer4 = new Observer(*subject);

    observer2->RemoveFromList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("Hello New World :)");
    observer5->RemoveFromList();

    observer4->RemoveFromList();
    observer1->RemoveFromList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    return 0;
}