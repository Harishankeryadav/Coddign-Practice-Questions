/*promise is an javaScript function it is not an run time function synchronush in nature.
syntax:    return new promise(function (resolve, reject){
    either 
    resolve(some data)
     or
    reject(some daata)
})

promish has 4 states
1. statush->either pending, fullfiled or rejected
2. value -> returned data or consumed data by using '.than' funtion of promis
3. fullfillment
4. rejected
*/
//example

// function checkNumber(val) {
//     return new Promise(function (resolve, reject) {
//         console.log("inside of the promish");
//         setTimeout(function () {
//             if (val % 2 == 0) {
//                 resolve("even");
//             }
//             else
//                 reject("odd");
//         }, 3000);
//     })
// }

// let x = checkNumber(4);
// console.log(x);

//example2-> to mimic the download the dask and writing the file and uploading the function with the given url

function downlaod(url){
    console.log("Downloading the file from -> ", url);
    return new Promise(function(resolve, reject){
        setTimeout(function(){
            resolve("downloading completed ");
            console.log("donwloading completed");
        }, 4000);
    });
}

function writeFile(fileAddr){
    return new Promise(function (resolve,reject){
        console.log("writing file is been done ");
        setTimeout(function(){
            resolve("file.txt");
            console.log("writing completed " );
        }, 4000);
    });
}

function uploadFile(url, file){
    let x = new Promise(function(resolve, reject){
        console.log("uploading file ->", url);
        setTimeout(function(){
            console.log("File has been uploaded sucessfully ");
            resolve("SUCESSFULL");

        },3000);
    })
    return x;
}

/*
.then() function is used to acces the returned promise object,  we make it this chain like structor to 
        remove the promise hell.
*/
let downloadFile = downlaod("www.xyz.com");
downloadFile.then(function (value){
   console.log("file donwloaded ", value);
    return value;
})
.then(function(value){
    let x = writeFile(value);
    // console.log(x.then());
    return x;
})
.then(function(value){
    console.log("file upload has been");
    return uploadFile("www.google.drive.com", value);
})