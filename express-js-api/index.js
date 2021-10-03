
 var express = require('express');
 var app = express();
 var port = 8080;
 const path = require('path')
 const { randomMeme } = require('./memes');
 const { kill } = require('./ded');
 const { Canvas } = require('canvas-constructor')
const canvas = require('canvas')
const axios = require('axios');

 app.listen(port, function() {
   console.log('app started');
 })
 

 app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname+'/public/index.html'));
 })



app.get('/meme', (req, res) => {
  res.json(randomMeme());
})

app.get('/killed', (req, res) => {
  res.json(kill());
})

app.get('/twitter',async  (req, res) => {
  var lmao = req.param('text')
  
  const img = await canvas.loadImage('https://teckspace.files.wordpress.com/2011/08/twitter1.jpg')

  let image = new Canvas(550, 267)
  .printImage(img, 0, 0, 550, 267)
  .setTextFont('18px Helvetica Neue')
  .printText(lmao, 40, 150)
  .toBuffer();

  res.set({'Content-Type': 'image/png'})
  res.send(image)

  
});

app.get('/kowalski',async  (req, res) => {
  var lolz = req.param('text')
  
  const img = await canvas.loadImage('https://i.redd.it/nis9eqae7qu11.png')

  let image = new Canvas(763, 400)
  .printImage(img, 0, 0, 763, 400)
  .setTextFont('18px Helvetica Neue')
  .printText(lolz, 455, 130)
  .toBuffer();

  res.set({'Content-Type': 'image/png'})
  res.send(image)

  
});

app.get('/woah',async  (req, res) => {
  var lol = req.param('text')
  const img = await canvas.loadImage('https://i.pinimg.com/474x/d0/5d/36/d05d367a5e0153bbd104805868d080a1.jpg')

  let image = new Canvas(466, 500)
  .printImage(img, 0, 0, 466, 500)
  .setTextFont('18px Helvetica Neue')
  .printText(lol, 106, 102)
  .toBuffer();

  res.set({'Content-Type': 'image/png'})
  res.send(image)

  
});



app.get('/lyrics',async  (req, res) => {
  
 
  const title = req.param('song')
  const author = req.param('author')
  const url = `https://api.lyrics.ovh/v1/${author}/${title}`

    let data, response;
        try {
            response = await axios.get(url);
            data = response.data;
        } catch (e) {
            return res.send(':( No Lyrics Found')
        }
  const lyricsxd = data.lyrics
  res.send(`{"lyrics": "${lyricsxd}"}`)

  
  


  
});



app.get('/trump',async  (req, res) => {
  var text = req.param('text');
  const img = await canvas.loadImage('https://i.imgflip.com/1i7abe.jpg')

  let image = new Canvas(585, 189)
  .printImage(img, 0, 0, 585, 189)
  .setTextFont('18px Segoe UI')
  
  .printText(text, 85, 55)
  .toBuffer();

  res.set({'Content-Type': 'image/png'})
  res.send(image)

  
});

app.get('/temp',async  (req, res) => {
  var bruh = req.param('text')
  
  const img = await canvas.loadImage('https://i.imgflip.com/41exj5.png')

  let image = new Canvas(1763, 1779)
  .printImage(img, 0, 0, 1763, 1779)
  .setTextFont('65px Poppins Bold')
  
  .printText(bruh, 1063, 956)
  .toBuffer();

  res.set({'Content-Type': 'image/png'})
  res.send(image)

  
});
