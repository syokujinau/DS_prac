module.exports = LinkedList;
function LinkedList() {
    "use strict";
    const Node = function(element){
        this.element = element;
        this.next = null;
    }
    let length = 0;
    let head = null;
    // 在前端(head)新增一個節點
    this.append = function(element){
        // new一個Node
        const node = new Node(element);
        let current;

        if(head === null){ //空串列，將head指向第一個node
            head = node;
        }
        else{ //
            node.next = head;
            head = node;
        }
        length++;
    };
    // 在特定位置之前新增一個元素節點
    this.insert = function(position, element){
        if(position >= 0 && position <= length){
            let node = new Node(element);
            let current = head;
            let previous;
            let index = 0;

            if(position === 0){
                node.next = current;
                head = node;
            }
            else{
                while(index < position){
                    previous = current;
                    current = current.next;
                    index++;
                }
                node.next = current;
                previous.next = node;
            }
            length++;
            return true;
        }
        else{
            console.log("[ERROR] position out of range.");
            return false;
        }
    };
    // 從串列中移除一個元素節點，並回傳該點;
    this.remove = function(element){
        let index = this.indexOf(element);
        return this.removeAt(index);
    };
    // 從串列中移除一個特定的節點
    this.removeAt = function(position){
        if(position > -1 && position < length){
            let current = head;
            let previous;
            let index = 0;
            if(position === 0){ // 刪除head node
                head = current.next;
            }
            else{
                while(index < position){ // 將current指向欲刪除位置
                    previous = current;
                    current = current.next;
                    index++;
                }
                previous.next = current.next;
            }
            length--;
            return current.element; //回傳該值
        }
        else{
            console.log('[ERROR] index out of range!')
            return null;
        }
    };
    // 回傳元素在串列的元素節點 index，若無則回傳 -1
    this.indexOf = function(element){
        let current = head;
        let index = 0;
        //console.log(current.element);
        while(current){
            if(element === current.element){
                return index;
            }
            index++;
            current = current.next;
        }
        return -1;
    };
    // 判斷串列是否為空，是回傳 true，反之 false
    this.IsEmpty = function(){
        return length === 0;
    };
    // 回傳串列元素個數
    this.size = function(){
        return length;
    };
    // 由於 Node 是一個物件，所以運用 toString 方法將資料值輸出
    this.toString = function(){
        // 建立一個變數幫助迴圈
        let current = head;
        let string = '';
        // 循序檢查 current 指到的 node 是否存在，若存在則串接資料內容成字串
        while(current) {
            string += current.element;
            string += ' => ';
            // 指到下一個元素
            current = current.next;
        }
        string += "NULL";
        return string;
    };
    // 列印出值
    this.print = function(){
        if(this.IsEmpty()){
            console.log('This is an empty linked-list.');
        }
        else{
            var str = this.toString();
            console.log(str);
        }
        console.log(''); //換行
    };
}


 
