let a = 5;
let b = 5;

temp = document.getElementById("row1col1").innerText;
temp2 = document.getElementById("row2col2").innerText;
temp3 = document.getElementById("test").innerText;
console.log(temp+temp2);
console.log(a+b);
console.log(temp3);

document.getElementById("row1col1").style.background = "black";

function validateForm(){
name = document.forms["form"]["Name"].value;
email = document.forms["form"]["Mail"].value;
age = document.forms["form"]["age"].value;

console.log(name);
console.log(email);
console.log(age);
}
