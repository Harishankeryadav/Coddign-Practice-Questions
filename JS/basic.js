// function
// function fun(x, fn){
//     for(let i = 0; i < x; i++){
//         console.log(i*i);
//     }
// }
// let x = 5;
// fun (x);

//function expression
// let run = function gun(arr){
//     console.log("inside gun");
//     for(let i =0; i < 5; i++){
//         console.log (i*i);
//     } 
// }

// let arr = [1,2,3,4]
// run(arr);
// console.log(run);



//function callback

// function fun(num, fn) {
//     for (let i = 0; i < num; i++) {
//         console.log("hello");
//     }
//     let arr = [1, 2, 3, 4, 5]
//     fn(arr);

// }

// fun(2, add);

// function add(arr) {
//     for (let i = 0; i < arr.length; i++) {
//         console.log(arr[i], arr[i] + i);
//     }
// }


// function fun(arr, gun){

//     console.log("hello world ");
// gun(arr);
// }

// let arr = [1, 4, 5, 9, 2];
// fun(arr, cuber);

// function cuber(arr){
//     for(let i = 0; i < arr.length; i++){
//         console.log(arr[i] ,  arr[i]*arr[i]*arr[i]);
//     }
// }


//array.map -> application of callback
//expect a callback function where map passes value and index of array and returns the processed array.

// let arr = [1,2,3,4,5];
// let array = arr.map(function fun(v, i){
//     console.log(v , i);
//     return v*v;
// });

// console.log(array);
// console.log(arr);

//setTimeout

// let ID = setTimeout(function(){
//     console.log("set timeout" );
// }, 2000);
// console.log(ID);

// setInterval(function(){
//     console.log("hello ");

// }, 1000);

// let id = setInterval(function () {
//     console.log("hello");
//     setTimeout(() => {                      // => this is called as arrow function it is  anonymous funntion
//         clearInterval(id)                   // clearInterval is used to halt/ stop the setInterval with the passed id.
//     }, 5000);
// }, 1000);


//spliting the given array
// function fun(array){
//     let ip = array.split(':');
//     for(let i = 0; i < ip.length; i++){
//         console.log(ip[i]);
//     }
// }


// var ipstr = ["asd:ljfvn", "asd:ir", "fg:ced", "de:e", "knb:rgv"];
// fun(ipstr);


// for (let i = 0; i < ipstr.length; i++) {
//     let ip = ipstr[i].split(':');
//     for (let j = 0; j < ip.length; j++) {
//         console.log(ip[j]);
//     }
// }
