// callbacks function

//inversion of control
// function fun(array, process) {
//     let ip = array.split(',');
//     console.log("ip :")
//     for(let i =0 ; i < ip.length; i++){
//         console.log(ip[i]);
//     }

//     for (let i = 0; i < ip.length; i++) {
//         process(ip[i]);
//     }

// }

// fun("name:hari, title:yadav, mid_name:shanker", function process(str) {
//     let ar = str.split(":");
//     console.log(ar[0], " => ", ar[1]);
// });


//taks: dummy function
//1. download form te given url and return the copntent 
//2.save the recieveed data in the file and tryturn the file name
//3. upload the data from downlaod form the prev function 

function downlaod(url , fn){
    console.log("downlaod the data from -> ", url);
    setTimeout(function process(){
        console.log("downloading data");
        let response = "dummy data ";
        fn(response);
    } ,3000);
}

function updatefile(data, fun){
    console.log("updaing the file ", data);
    let fileName = "xyz.txt";
        setTimeout(function process(){
            console.log("file updated")
            fun(fileName);
        },4000);
}

function upload(url, file, fn){
    console.log("uploading the data at -> ", url);
    setTimeout(function process(){
        console.log("uploading data");
        let response = "SUCCESFULL";
        fn(response);
    } ,5000);
}

downlaod("www.google.com", function fn(response){
    console.log("downlaod completed", response);

     updatefile(response, function (fileName){
        console.log("data update on file -> ", fileName);

        upload("www.drive.google.com", fileName, function(response){
            console.log("upload", response);
        })
    });
});

