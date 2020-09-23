// Logging something to the console

let person = {
        firstName: 'Gustavo',  // String literal
        lastName: 'Casanova',  // String literal
        age: 49,               // Number literal
        isApproved: true      // Boolean literal
};

let animal = {
    species: undefined,
    isMammal: true,
    legs: 4
};

let und = undefined;        // Undefined
let selection = null;       // Null

const interestRate = 0.3;
//interestRate = 1;

animal['species'] = 'dog';
animal_leg_property = 'legs';
animal[animal_leg_property] = 4;

const selectedColors = ['red', 'blue', 123];
selectedColors[5] = 'brown';

// Function greet someone
function greet(firstName, lastName) {
    console.log('Hello ' + firstName + ' ' + lastName);
}

// Function square
function square(number) {
    return number * number;
}

let numberToSquare = square(3);

const quien = `Yo soy ${person.firstName} ${person.lastName}, y tengo ${person.age} años ...`;

console.log(person.firstName + ' ' + person.lastName);
console.log('Interest rate allowed: ' + interestRate);

console.log('The animal is a ' + animal.species + ', it has ' + animal[animal_leg_property] + ' legs');

//console.log('Color: ' + selectedColors[1]);
console.log(selectedColors);


greet(person.firstName, person.lastName);

console.log('Squared number: ' + numberToSquare);

console.error('ERROR: Garnacha!');

console.log(quien);
