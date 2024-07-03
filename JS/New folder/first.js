const http = require('http');
const port = 5500;





const server  = http.createServer(
    function exec (request, response){
        if(request.url == '/home'){
            response.end("welcome to home ");
        }
        else if(request.url == '/file'){
            console.log("file ");
        }
        else{
            console.log("welcome at page ");
        }

    }
);

server.listen(port , function process(){

    console.log("Server started on port ",port);
});
