
# 💻 Docker Environment for C Development

## 🚀 Build and Start the Container
```bash
docker-compose up --build -d
```
## 🖥️ Attach Container via Shell
```bash
docker attach c_dev_container 
```
## 🖥️ Star Container via Shell
```bash 
docker-compose start c_dev_container
```
## 🖥️ Access the Container via Shell
```bash
docker exec -it c_dev_container /bin/zsh
```

## 🖥️ Remove All Containers via Shell
```bash
docker container rm $(docker container ls -a -q) -f
```
## 🖥️ Remove All Images via Shell
```bash
docker image rm $(docker image ls -q)
```

