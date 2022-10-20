FROM python:alpine3.15
WORKDIR /opt/kessler/machine_controller
EXPOSE 8000
COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt
#EXPOSE 80

COPY . .
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
CMD ["gunicorn", "--bind", "0.0.0.0:8000", "--workers=2", "machine_controller.wsgi"]