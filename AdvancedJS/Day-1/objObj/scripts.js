var i = 0;
var LnkdLstObj = {
    data: [],
    push: function (value) {
        if (this.data.length > 0) {
            if (value > this.data[this.data.length - 1]["val"]) {
                var obj = { val: value }
                LnkdLstObj.data.push(obj);
            }
            else {
                throw ": Can't push,The values must be ordered"
            }
        }
        else {
            var obj = { val: value }
            LnkdLstObj.data.push(obj);
        }

    },
    pop: function () {
        var x = LnkdLstObj.data.pop();
        console.log(x.val);
    },
    enque: function (value) {
        if (this.data.length > 0) {
            if (value < this.data[0].val) {
                var obj = { val: value }
                this.data.unshift(obj);
            }
            else {
                throw ": Can't enque,The values must be ordered"
            }
        }
        else {
            var obj = { val: value }
            this.data.unshift(obj);
        }
    },
    deque: function () {
        console.log(this.data.shift().val);
    },
    insert: function (value, index) {
        if (arguments.length < 2) {
            throw new Error("you have to pass the index")
        }
        var flag = 0;
        for (i = 0; i < this.data.length; i++) {
            if (this.data[i].val == value) {
                flag = 1
            }
        }
        if (flag) {
            throw "can't insert an existing value";
        }
        else {
            if (index == 0 && value < this.data[0].val) {
                this.enque(value);
            }
            //is push right?
            else if (index == this.data.length - 1 && value > this.data[this.data.length - 1].val) {
                this.push(value);
            }

            else if (value > this.data[index - 1].val && value < this.data[index].val) {
                for (i = this.data.length - 1; i >= index; i--) {
                    this.data[i + 1] = this.data[i];
                }
                var obj = { val: value }
                this.data[index] = obj;
            }
            else throw ": Can't insert,The values must be ordered"
        }

    }
}

