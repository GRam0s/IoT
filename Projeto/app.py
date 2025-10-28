from flask import Flask, render_template, jsonify
import serial
import time
import threading

# Conexão com Arduino
try:
    arduino = serial.Serial('COM6', 9600, timeout=1)
    time.sleep(2)
    print("✅ Conectado ao Arduino na porta COM6")
except serial.SerialException as e:
    print(f"❌ Erro ao conectar com Arduino: {e}")
    arduino = None

app = Flask(__name__)
temperatura_atual = "--"

def ler_dados_arduino():
    global temperatura_atual
    if not arduino:
        return
    while True:
        try:
            linha = arduino.readline().decode('utf-8').strip()
            if linha.startswith("Temperatura:"):
                valor = linha.replace("Temperatura:", "").replace("*C", "").strip()
                temperatura_atual = valor
        except Exception as e:
            print(f"Erro ao ler Arduino: {e}")
        time.sleep(1)

threading.Thread(target=ler_dados_arduino, daemon=True).start()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/temperatura')
def temperatura():
    return jsonify({"temperatura": temperatura_atual})

if __name__ == '__main__':
    print("Servidor Flask iniciado! Acesse http://localhost:5000")
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
