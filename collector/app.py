from flask import Flask, request
import json

app = Flask(__name__)

@app.route('/test',methods=['POST'])
def foo():
   data = json.loads(request.data)
   print("Incoming: {}".format(data['username']))
   return "OK"

if __name__ == '__main__':
   app.run()