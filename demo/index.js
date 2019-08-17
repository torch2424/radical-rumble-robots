import { WasmBoy } from '../node_modules/wasmboy/dist/wasmboy.wasm.esm.js';

const canvas = document.querySelector('canvas');

const playROM = async () => {
  await WasmBoy.config({});
  await WasmBoy.setCanvas(canvas);
  await WasmBoy.loadROM("../dist/main.gb");
  WasmBoy.play();
} 
playROM();
