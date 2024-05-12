import * as readline from 'readline';

interface TodoItem {
    name: string;
    completed: boolean;
}

class TodoList {
    private list: TodoItem[] = [];

    addToList(name: string) {
        let todoItem: TodoItem = {
            name: name,
            completed: false
        };
        this.list.push(todoItem);
    }

    printList() {
        this.list.forEach((item, index) => {
            let status = item.completed ? 'Done' : 'Not Done';
            console.log(`${index} ${item.name} - ${status}`);
        });
    }

    markDone(index: number) {
        if (index < this.list.length) {
            this.list[index].completed = true;
        }
    }
}

let todoList = new TodoList();
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function mainMenu() {
    console.log("1) Add to list");
    console.log("2) Mark done");
    console.log("3) Show list");
    console.log("4) Quit");

    rl.question("Choose an option: ", function(choice) {
        switch(choice) {
            case '1':
                rl.question("Enter your task: ", function(task) {
                    todoList.addToList(task);
                    mainMenu();
                });
                break;
            case '2':
                rl.question("Enter task number to mark as done: ", function(taskNum) {
                    todoList.markDone(parseInt(taskNum));
                    mainMenu();
                });
                break;
            case '3':
                todoList.printList();
                mainMenu();
                break;
            case '4':
                rl.close();
                break;
            default:
                console.log("Please enter a valid choice");
                mainMenu();
                break;
        }
    });
}

mainMenu();
