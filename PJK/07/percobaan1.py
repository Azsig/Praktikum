from flask import Flask, request, jsonify

app = Flask(__name__)

#Sample data storage (acts lik a simple database)
data = {}

#Get method to retrieve data
@app.route('/data/<key>', method = ['GET'])
def get_data(key):
    if key in data:
        return jsonify({key: data[key]}), 200
    else:
        return jsonify({'error': "key not found"}), 404

#POST method to add new date
@app.route('/data', method = ['POST'])
def post_data():
    request_data = request.json
    key = request_data.get('key')
    value = request_data.get('value')
    if key and value:
        data[key]=value
        return jsonify({"message":"Data added"}), 201
    return jsonify({"error":"Bad Request"}), 400

#PUT method to update data
@app.route
