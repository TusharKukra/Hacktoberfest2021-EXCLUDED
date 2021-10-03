const memes = require('./endpoints/meme.json');
const randomMeme = () => {
    return memes[Math.floor(Math.random() * memes.length)];
  }

  module.exports = {  randomMeme };