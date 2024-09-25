#include <iostream>
#include <string>
#include <vector>
#include "AVLTree.h"

int main() {
    //Get the number of commands and turn it into an integer
    std::string numOfCommandsString;
    std::getline(std::cin, numOfCommandsString);
    int numOfCommands = std::stoi(numOfCommandsString);

    //Create AVL tree object
    AVLTree studentTree = AVLTree();

    //Iterate through all the commands and call functions as necessary
    std::string command;
    std::vector<std::string> commandList;

    for (int i = 0; i < numOfCommands; i++) {
        //get the command and separate it by spaces
        std::getline(std::cin, command);
        int index = 0;
        for (int j = 0; j < (int) command.size(); j++) {
            if (char(command[j]) == ' ' && (char(command[j + 1]) == ' ')) {
                //make sure there aren't multiple spaces in a row
                std::cout << "unsuccessful" << std::endl;
                break;
            }
            if (char(command[j]) == '"') {
                //if the command is a name then don't separate at the space
                while (j < (int) command.size()) {
                    j++;
                    if (!isalpha(char(command[j])) && char(command[j]) != ' ' && char(command[j]) != '"') {
                        //if any of the characters between the parenthesis aren't alphabetical or a space
                        commandList[0] = " ";
                        break;
                    }
                    if (char(command[j]) == '"') {
                        j++;
                        commandList.push_back(command.substr(index, j - index));
                        index = j + 1;
                        //std::cout << index << std::endl;
                        break;
                    } else if (j == (int) command.size()) {
                        //if the parenthesis are never closed break and make sure it returns unsuccessful
                        commandList[0] = " ";
                        break;
                    }
                }
            } else if (char(command[j]) == ' ') {
                commandList.push_back(command.substr(index, j - index));
                index = j + 1;
                continue;
            } else if (j == ((int) command.size()) - 1) {
                //this is for the last command because there is no space to remove
                commandList.push_back(command.substr(index, j - index + 1));
            }
        }
        /*test commandList
        for(auto v: commandList){
            std::cout << v << std::endl;
        }*/



        //Do stuff based off the command
        if (commandList[0] == "insert") {
            //make sure there are only 3 commands
            if (commandList.size() > 3 || commandList[2].size() != 8) {
                //make sure there are the right amount of command and the ID is the right length
                std::cout << "unsuccessful size/commandlength" << std::endl;
                index = 0;
                commandList.clear();
                continue;

            }
            for(auto n: commandList[2]){
                if(!std::isdigit(n)){//if the 3rd command contains a non digit
                    std::cout << "unsuccessful digit" << std::endl;
                    index = 0;
                    commandList.clear();
                    continue;
                }
            }
            //std::cout << commandList[2];
            studentTree.insert(commandList[1], std::stoi(commandList[2]));
        } else if (commandList[0] == "remove") {

        } else if (commandList[0] == "search") {

            //check if you are searching for id or name first
            if (std::isalpha(commandList[1][0])) {
                //search for name
            } else {
                //search for ID
            }
        } else if (commandList[0] == "printInorder") {
            studentTree.printInOrder(studentTree.head);

        } else if (commandList[0] == "printPreorder") {

        } else if (commandList[0] == "printPostorder") {

        } else if (commandList[0] == "printLevelCount") {

        } else if (commandList[0] == "removeInorder") {

        } else {
            std::cout << "unsuccessful" << std::endl;
        }

        //Reset variables between command inputs
        index = 0; //reset index
        commandList.clear(); //clear the commandList for the next command
        commandList[0] = "";//do this for some reason (possibly undefined behavior)
    }

    return 0;
}
