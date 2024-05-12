//Find the Minimum Cost Array Permutation in Todo-ist
use std::io::{self, Write};
use std::collections::LinkedList;

struct TodoItem {
    name: String,
    completed: char,
}

impl TodoItem {
    fn new(name: String) -> TodoItem {
        return TodoItem {
            name: name,
            completed: ' ',
        };
    }
}

struct TodoList {
    list: LinkedList<TodoItem>,
}

impl TodoList {
    fn new() -> TodoList {
        return TodoList {
            list: LinkedList::new(),
        };
    }

    fn add_to_list(&mut self, name: String) {
        let todo_item = TodoItem::new(name);
        self.list.push_back(todo_item);
    }

    fn print(&self) {
        for (i, item) in self.list.iter().enumerate() {
            println!("{} [{}] - {}", i, item.completed, item.name);
        }
    }

    fn mark_done(&mut self, index: usize) {
        let mut i = 0;
        for item in self.list.iter_mut() {
            if i == index {
                item.completed = 'x';
                break;
            }
            i += 1;
        }
    }
}

fn main() {
    let mut todo_list = TodoList::new();

    loop {
        println!("1) Add to list");
        println!("2) Mark done");
        println!("3) Show list");
        println!("4) Quit");

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).expect("Failed to read line");

        let choice = choice.trim().parse::<u32>().expect("Please enter a number");

        match choice {
            1 => {
                print!("Enter your task: ");
                io::stdout().flush().expect("Failed to flush stdout");

                let mut task = String::new();
                io::stdin().read_line(&mut task).expect("Failed to read line");

                todo_list.add_to_list(task);
            },
            2 => {
                print!("Enter task number to mark as done: ");
                io::stdout().flush().expect("Failed to flush stdout");

                let mut task_num = String::new();
                io::stdin().read_line(&mut task_num).expect("Failed to read line");

                let task_num = task_num.trim().parse::<usize>().expect("Please enter a number");

                todo_list.mark_done(task_num);
            },
            3 => {
                todo_list.print();
            },
            4 => {
                break;
            },
            _ => {
                println!("Please enter a valid choice");
            },
        }
    }
}
