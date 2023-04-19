const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line.split(" ")); // 문자열
});




rl.on("close", () => {
  for(let i=0; i<input.length; ++i){
    input[i] = input[i].map(element => Number(element));
  }
  console.log(input[0][0]+input[0][1]);
  process.exit();
});
