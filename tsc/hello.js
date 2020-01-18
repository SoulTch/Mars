var Person = /** @class */ (function () {
    function Person(name) {
        this.name = name;
    }
    Person.prototype.greet = function () {
        return this.name;
    };
    return Person;
}());
console.log(new Person("my name").greet());
