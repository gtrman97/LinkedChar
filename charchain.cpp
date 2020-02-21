/*--------------------------------------------------------
 * Name: Andrew Killian
 *
 * Program to illustrate a menu of options
 * to create, modify and display a linked list of characters.
 --------------------------------------------------------*/

#include <iostream>

class Node {
private:
    char item;
    Node * nextPtr;
public:
    Node(){}

    Node(char item) : item(item),nextPtr(nullptr) {}

    char getItem() const {
        return item;
    }

    void setItem(char item) {
        Node::item = item;
    }

    Node *getNext() const {
        return nextPtr;
    }

    void setNext(Node *nextPtr) {
        Node::nextPtr = nextPtr;
    }

};

class LinkedChar {
private:
    Node * headPtr;
    int itemcount;
public:
    LinkedChar () : headPtr(nullptr) {}

    LinkedChar (const std::string word) : headPtr(nullptr), itemcount(0){

        for(int i = word.length()-1; i>= 0; i--){

            add(word[i]);

        }

    }

    int length() const{

        return itemcount;

    }

    int index(char ch) const {
        int charIndex = 0;
        Node *currNodePtr = headPtr;

        while (currNodePtr != nullptr) {
            charIndex++;


        if (currNodePtr->getItem() == ch) {
            return charIndex;

        }
            currNodePtr = currNodePtr->getNext();

        }
        return -1;
    }

    void append(const LinkedChar& lc){
        itemcount += lc.itemcount;
        Node *origChainPtr = lc.headPtr;

        Node *prevNodePtr = headPtr;
        Node *currNodePtr = headPtr->getNext();

        while(currNodePtr != nullptr) {
            prevNodePtr = currNodePtr;
            currNodePtr = currNodePtr->getNext();
        }

        while(origChainPtr != nullptr){

                char nextItem = origChainPtr->getItem();

                Node *newNodePtr = new Node(nextItem);

                prevNodePtr->setNext(newNodePtr);

                prevNodePtr = prevNodePtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }

            prevNodePtr->setNext(nullptr);

        }

    bool subMatch(const LinkedChar& lc) const {
        Node *origChainPtr = headPtr;
        Node *newChainPtr = lc.headPtr;

        while(origChainPtr != nullptr){

        while(origChainPtr->getItem() == newChainPtr->getItem()) {

            origChainPtr = origChainPtr->getNext();
            newChainPtr = newChainPtr->getNext();

            if(newChainPtr == nullptr){
                return true;

            }

        }
        origChainPtr = origChainPtr->getNext();
        newChainPtr = lc.headPtr;
        }



        return false;

    }

    void add(char item) {
        Node *newNodePtr = new Node(item);
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
        itemcount++;
    }

    void display() const {
        Node *currNodePtr = headPtr;
        //std::cout << "bag - " << head << " : ";

        while(currNodePtr != nullptr) {
            std::cout << " - " << currNodePtr->getItem() << " ";
            currNodePtr = currNodePtr->getNext();
        }
        std::cout << std::endl;
    }
    void clear () {

        while (headPtr !=nullptr) {
            Node *deleteNodePtr = headPtr;
            headPtr = headPtr->getNext();
            delete deleteNodePtr;
        }
    }

    ~LinkedChar () { clear(); }
};
int main() {

    int num = 0;
    LinkedChar linkedChar1;
    LinkedChar linkedChar2;
    LinkedChar *lc1;
    LinkedChar *lc2;


    while(num != 7){

        std::cout << "1. new string\n";
        std::cout << "2. length\n";
        std::cout << "3. find index of char\n";
        std::cout << "4. append string\n";
        std::cout << "5. find submatch\n";
        std::cout << "6. display string list\n";
        std::cout << "7. quit\n";
        std::cin >> num;
        std::cin.ignore();
        if(num == 1){
            std::string phrase;
            std::cout << "Enter a phrase to put into a linked list: ";
            std::getline (std::cin, phrase);
            lc1 = new LinkedChar(phrase);

        }

    if(num==2){
        int x = lc1->length();
        std::cout << "Length of your list is " << x << std::endl;

    }if(num==3){
        char letter;
        std::cout << "Enter a character to search for: ";
        std::cin >> letter;
        std::cin.ignore();
        int i = lc1->index(letter);
        std::cout << "This character is at index " << i << std::endl;

    }if(num==4){
        std::string lsappend;
        std::cout << "Enter a string to append: ";
        std::getline (std::cin, lsappend);
        lc2 = new LinkedChar(lsappend);
        lc1->append(*lc2);


    }if(num==5){
        std::string sub;
        std::cout << "Enter a string to search for: ";
        std::cin >> sub;
        bool t = lc1->subMatch(sub);
        if(t){
            std::cout << "This string is within the list!\n";
        }else{
            std::cout << "This string is not within the list...\n";
        }
    }if(num==6){
        lc1->display();
    }}


    return 0;
}
