import asyncio as asy
import websockets

localhost = "192.168.78.174"
PORT = 5000

async def echo(websocket, path):
    async for message in websocket:
        print(f"Received from client : {message}")
        response = f"Server received : {message}"
        await websocket.send(response)
async def main():
    async with websockets.serve(echo, localhost, PORT):
        print(f"websocket server started at ws://{localhost}:{PORT}")
        await asy.Future()

if __name__ == "__main__":
    asy.run(main())