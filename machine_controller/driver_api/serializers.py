from rest_framework import serializers

from .models import Param


class ParamSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Param
        fields = ['id', 'param_id', 'index', 'label', 'value', 'timestamp', 'device_type', 'component_type']
        read_only_fields = ['id', 'param_id', 'index', 'label', 'device_type', 'component_type']
