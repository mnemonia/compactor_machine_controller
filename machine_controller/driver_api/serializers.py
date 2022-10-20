from rest_framework import serializers

from .models import Command, Param


class ParamSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Param
        fields = ['id', 'param_id', 'index', 'label', 'value', 'timestamp', 'device_type', 'component_type']
        read_only_fields = ['id', 'param_id', 'index', 'label', 'device_type', 'component_type']

class ConfigParamValueSerializer(serializers.ModelSerializer):
    class Meta:
        model = Param
        fields = ['param_id', 'value']
        # read_only_fields = fields

class CommandSerializer(serializers.ModelSerializer):
    class Meta:
        model = Command
        fields = ['command_id','must_run']
