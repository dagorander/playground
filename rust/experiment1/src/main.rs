// From the file read and write
use std::fs::File;
use std::io::prelude::*;

// From the json
extern crate serde_json;
extern crate serde;
#[macro_use] // Allows us to use a struct for serialise/deserialise
extern crate serde_derive;

use serde_json::Value as JsonValue;

// To let us do some io
use std::io;

// Grabbing a source file
mod secondfile; // simply filename, what about nested folders?
mod testfolder { // nests as if the folders are folders
    pub mod nestedfile; // otherwise counts as private module!
}

// Hashmaps
use std::collections::HashMap;

// Struct for json_method_two
#[derive(Serialize, Deserialize)] // gives traits from serde_json to the struct
struct Person {
    name: String,
    age: u8,
    is_male: bool
}

fn main() {
    header_text();
    read_a_text_file();
    write_file_and_read_back();
    json_method_one();
    json_method_two();
    secondfile::print_message();
    testfolder::nestedfile::print_message_from_subfolder();
    // That was ugly, deduced from here:
    // https://stackoverflow.com/questions/58935890/how-to-import-from-a-file-in-a-subfolder-of-src
    // TODO: figure out if I can use "as" to access cleaner.
    take_and_read_input();
    hashmap();
    footer_text();
}

fn hashmap() {
    // More about that here:
    // https://www.reddit.com/r/rust/comments/7rgowj/hashmap_vs_btreemap/
    // Can use serde to read/write hashmaps to files
    // Hashmap documentation: https://doc.rust-lang.org/std/collections/struct.HashMap.html
    let mut marks = HashMap::new();

    // Add values
    marks.insert("Sexiness", 10);
    marks.insert("Hurpedurp", 8);
    marks.insert("UGHABOOOGA", 1);
    marks.insert("Last one", 0);

    // Find length of HashMap
    println!("How many are there in the map? {}", marks.len());

    // Get a single value
    match marks.get("Sexiness") {
        Some(mark) => println!("You have {} for Sexiness", mark),
        None => println!("You have no Sexiness!")
    }

    // Remove a value
    marks.remove("UGHABOOOGA");

    // Loop through HashMap
    for (topic, mark) in &marks {
        println!("For {} you have {}", topic, mark);
    }

    // Check for value
    println!("Do you have Cornholio? {}", marks.contains_key("Cornholio"));
}

fn take_and_read_input() {
    let mut input = String::new();
    println!("Make some input:");
    match io::stdin().read_line(&mut input) { // match?
        // Match lets us deal with errors and such.
        //Ok(b) would give access to byte size of input, _ ignores that
        Ok(_) => {
            println!("Yay! You said: {}", input.to_uppercase());
        },
        Err(e) => println!("Oooops, something broke: {}", e),

    }
    spacer();
}

fn json_method_two() {
    // uses two extra crates serde and serde_derive
    let json_str = r#"
        {
            "name": "Daniel",
            "age": 38,
            "is_male": true
        }
    "#;

    let result = serde_json::from_str(json_str);

    if result.is_ok() {
        let passed: Person = result.unwrap(); // Deserialised and stored in passed?
        println!("The name is {}", passed.name);
        println!("The age is {}", passed.age);
        println!("Are they male? {}", passed.is_male);
    } else {
        println!("Could not parse JSON (method one)");
    }

    spacer();
}

fn json_method_one() {
    // Uses serde_json and the use value as jsonvalue only
    // TODO: this "raw string" seems like it lets us do formatting and
    //          multi-line strings and such things?
    let json_str = r#"
        {
            "name": "Daniel",
            "age": 38,
            "is_male": true
        }
    "#;

    let result = serde_json::from_str(json_str);

    if result.is_ok() {
        let passed: JsonValue = result.unwrap(); // Deserialised and stored in passed?
        println!("The name is {}", passed["name"] // Weirdo array style syntax
            .as_str().unwrap()); // Gets rid of the ", unwrap is unsafe here tho
    } else {
        println!("Could not parse JSON (method one)");
    }

    spacer();
}

fn write_file_and_read_back() {
    let mut file = File::create("writtenfile.txt")
        .expect("Could not create the file.");

    // TODO: Below we create a byte slice. Why and what are they?
    file.write_all(b"Welcome to your new file!")
        .expect("Failed writing to the file");

    file = File::open("writtenfile.txt")
        .expect("Could not reopen the new file.");

    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .expect("Failed reading the new file.");
    
    println!("New file Content:\n\n{}", contents);

    spacer();
}

fn read_a_text_file() {
    let mut file = File::open("firstfile.txt").expect("Failed loading file.");

    let mut contents = String::new();
    file.read_to_string(&mut contents).expect("Failed reading the file.");

    println!("File Content:\n\n{}", contents);

    spacer();
}

fn header_text() {
    println!("\n\n\n\n########################################");
    println!("#            THIS IS A TEST            #");
    println!("#                                      #");
    spacer();
}

fn footer_text() {
    println!("#                                      #");
    println!("#             TEST IS OVER             #");
    println!("########################################\n\n\n\n");
}

fn spacer() {
    println!("\n########################################\n");
}