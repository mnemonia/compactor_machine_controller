from django.db import models
from django.utils import timezone

class Param(models.Model):
    SENSOR = 'SENSOR'
    ACTOR = 'ACTOR'
    DEVICE_TYPE_CHOICES =  [
        (SENSOR, 'Sensor'),
        (ACTOR, 'Aktor'),
    ]
    OPERATING_MODE = 'OPERATING_MODE'
    HEATING = 'HEATING'
    AGGREGATE = 'AGGREGATE'
    LAMP = 'LAMP'
    VALVE = 'VALVE'
    COMPACTOR = 'COMPACTOR'
    COMPONENT_TYPE_CHOICES =  [
        (OPERATING_MODE, 'Betriebsart'),
        (HEATING, 'Heizung'),
        (AGGREGATE, 'Hydraulik Aggregat'),
        (LAMP, 'Lampe'),
        (VALVE, 'Ventil'),
        (COMPACTOR, 'Presse'),
    ]
    NOMINAL = 'NOMINAL'
    ACTUAL = 'ACTUAL'
    STATE = 'STATE'
    PARAM_TYPE_CHOICES = [
        (NOMINAL, 'Sollwert'),
        (ACTUAL, 'Istwert'),
        (STATE, 'Zustand'),
    ]
    id = models.AutoField(primary_key=True)
    param_id = models.IntegerField(unique=True) 
    index = models.IntegerField(default=1)
    label = models.CharField(max_length=300)
    value = models.IntegerField(default=0)
    device_type = models.CharField(
        max_length=6,
        choices=DEVICE_TYPE_CHOICES,
        default=ACTOR,
    )
    component_type = models.CharField(
        max_length=44,
        choices=COMPONENT_TYPE_CHOICES,
        default=HEATING,
    )
    param_type = models.CharField(
        max_length=44,
        choices=PARAM_TYPE_CHOICES,
        default=NOMINAL,
    )
    timestamp = models.DateTimeField(default=timezone.now())
