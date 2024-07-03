function download(url) {
    return new Promise(function (resolve, reject) {
        console.log("Downloading the file from -> ", url);
        setTimeout(function () {
            resolve("SUCCESSFULL");
        }, 1000);
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

// async function processing() {
//     console.log("Downlaod 1 started");
//     let val1 = await download("www.gogole.drive.com");
//     console.log("download 1 done ", val1);
//     let val2 = await download("www.youtube.com");
//     console.log("downloading done of youtube", val2);
//     return val1 + val2;
// }

// console.log("START");
// setTimeout(function timer1() { console.log("timer 1") }, 0);
// console.log("After setting timer 1");
// let x = processing();
// x.then(function (value) {
//     console.log("finally processing promise resolves  with ", value);
// });
// setTimeout(function timer2() { console.log("timer2") }, 1000);
// setTimeout(function timer3() { console.log("timer3") }, 0);
// console.log("END")


//to remove the .then hell we can use promise.all() -> which can take multiple promisese at a time retrun altogether in an array if success
// and in case any one promise is rejecected all the promises get rejected
//and on the other hand we can use promise.any() instead of promise.all() it will return if any process is resolved.

async function process1(){
    console.log("inside of 1st process");
    let val = await download("www.google.com");
    console.log("uploading file");
    let val1 = await uploadFile("www.google.drive.com", val);
    return val1;
}
async function process2(){
    console.log("inside of 1st process");
    let val = await download("www.google.com");
    console.log("uploading file");
    let val1 = await uploadFile("www.google.drive.com", val);
    return val1;
}
async function process3(){
    console.log("inside of 1st process");
    let val = await download("www.google.com");
    console.log("uploading file");
    let val1 = await uploadFile("www.google.drive.com", val);
    return val1;
}

console.log("before promise.all function ");

Promise.all([process1(), process2(),process3()]).then(function(value){
    console.log("value of all the process are " ,value);
})

console.log("after promise.all function ");
