
var RandomizedSet = function() {
    this.set = [];
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (this.set.findIndex(ele => ele ===val) === -1) {
        this.set.push(val);
        return true;
    }
    return false;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    
    const idx = this.set.findIndex(ele => ele ===val);
    if (idx !== -1) {
        this.set.splice(idx, 1);
        return true;
    }
    return false;
}

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    function getRandomInt(max) {
      return Math.floor(Math.random() * max);
    }

    return this.set[getRandomInt(this.set.length)];
};

/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */