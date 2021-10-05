FROM python:3.8
WORKDIR /home/j/python/Python
RUN apt-get update && apt-get install -y netcat
COPY pip-requirements.txt /home/j/python/Python
RUN pip3 install --upgrade pip && \
    pip3 install -r pip-requirements.txt
COPY . /home/j/python/Python
