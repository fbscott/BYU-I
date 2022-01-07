class Person {
    constructor(name, course) {
        this.name = name;
        this.course = course;
    }
    
    greeting() {
        return `<h1>Hello, ${this.name}.<br />Welcome to ${this.course}.</h1>`;
    }
}

module.exports = Person;
