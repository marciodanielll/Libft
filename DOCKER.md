
# 💻 Docker Environment for C Development

## 🚀 Build and Start the Container
```bash
docker-compose up --build
```
- Builds the image and starts the `c_dev_container`.

## 🖥️ Attach Container via Bash
```bash
docker attach c_dev_container 
```

## 🖥️ Access the Container via Bash
```bash
docker exec -it c_dev_container /bin/bash
```
- Opens an interactive Bash terminal in the container.

## 📌 Useful Commands
- **Stop:**  
  ```bash
  docker-compose down
  ```
- **Restart:**  
  ```bash
  docker-compose up
  ```
- **Logs:**  
  ```bash
  docker logs c_dev_container
  ```

## 📂 Project Structure
```
|-- Dockerfile
|-- docker-compose.yml
|-- workspace/  # Mapped to /workspace in the container
```

## 🛠️ Tips
- Ensure **Docker** and **Docker Compose** are installed.
- Files in **workspace/** are accessible at `/workspace` in the container.