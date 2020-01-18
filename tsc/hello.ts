class Person {
    name : string;

    constructor(name : string) {
        this.name = name;
    }

    greet() : string {
        return this.name;        
    }
}

console.log(new Person("my name").greet());