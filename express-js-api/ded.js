
const killed = require('./endpoints/passout.json');


const kill = () => {
  return killed[Math.floor(Math.random() * killed.length)];
}




module.exports = {  kill };

