var LinkedList = require("./LinkedList");

var myLink = new LinkedList;

console.log("[TEST] 印出空串列");
myLink.print(); 

console.log("[TEST] append 1~10");
for(var i = 1; i <= 10; i++){
    myLink.append(i);
}
myLink.print(); 


console.log("[TEST] remove 值為5的Node");
myLink.remove(5);
myLink.print();

console.log("[TEST] remove index = 8 的Node (head的index為0)");
myLink.removeAt(8);
myLink.print();

console.log("[TEST] insert 特定位置");
myLink.insert(0, 11);
myLink.print();

myLink.insert(9, 1);
myLink.print();

myLink.insert(5, 6.5);
myLink.print();

console.log("[TEST] size");
console.log("size = ", myLink.size());
