## Run the Backend first
![Image](https://github.com/user-attachments/assets/6cd9155a-45ba-4763-aec4-312e47d67bb5)
![Image](https://github.com/user-attachments/assets/6ff9af65-3d5a-4378-b801-71057a184d02)
![Image](https://github.com/user-attachments/assets/ff43e810-c401-40d5-8ea2-c1a26fefebed)
Install Dependencies:
```bash
cd backend
python -m venv venv
source venv/bin/activate  # For Mac/Linux
venv\Scripts\activate     # For Windows
pip install -r requirements.txt
```

Startup Backend
```bash
python main.py
``` 

Call endpoiint to create db
```bash
curl -X POST http://localhost:5000/api/create-and-load
```
You should see a bosch.db file in the **/backend** folder.
If it doesnt work, replace localhost with 127.0.0.1

See the table
```bash
curl http://localhost:5000/api/view-data
```

## Run the frontend
Install dependencies
```bash
cd frontend
npm install --legacy-peer-deps
```

Spin up the frontend
```bash
npm run dev
```

Access frontend at http://localhost:3000

