(function(){
	// node.js でシリアル入力を受け取るテスト
	// via : http://tomowatanabe.hatenablog.com/entry/2013/03/23/233554

	// install "serialport"
	// $ npm install serialport

	// start node server.
	// $ node node.js


	var serialport = require('serialport');

	// Serial Port
	// var portName = '/dev/tty.usbmodemfd13431'; // Mac環境
	var portName = '/dev/tty.usbmodem1421'; // Mac環境
	var sp = new serialport.SerialPort(portName, {
	    baudRate: 9600,
	    dataBits: 8,
	    parity: 'none',
	    stopBits: 0,
	    flowControl: false,
	    parser: serialport.parsers.readline("\n")   // ※修正：パースの単位を改行で行う
	});

	// data from Serial port
	sp.on('data', function(input) {
		var buffer = new Buffer(input);
		console.log(buffer.toString('utf8'));
	});

	console.log(portName);
	console.log('Standby.');

})();
