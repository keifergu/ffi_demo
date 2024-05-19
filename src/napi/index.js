const addon = require('./build/Release/addon');

console.log('Result:', addon.add(2, 3));
new Promise((resolve) => {
    setTimeout(() => {
        resolve()
    }, 1000000);
})