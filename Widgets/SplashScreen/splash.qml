import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4
//import com.pasmart.appDefines 1.0

Item {
    id: element
    width: 600
    height: 600
//    FontLoader {
//        id: bMitraFont;
//        source: "qrc:/fonts/res/fonts/B Mitra.ttf"
//    }

    Image {
        id: image
        anchors.fill: parent
        source: "/images/image/splashBG1.jpg"

        Text {
            x: 50
            y: 473
            width: 379
            height: 16
            color: "#000000"
            text: "http://mohammad1893.ir .::. mohammadmehdi1893@gmail.com"
//            font.family: "Times New Roman"
//            font.pixelSize: 15
        }

        Text {
            x: 50
            y: 495
            width: 379
            height: 25
            color: "#000000"
            text: "©copyright 2020-2030 Mohammad 1893 . All rights receved."
//            font.family: "Times New Roman"
//            font.pixelSize: 15
        }

        Rectangle {
            id: appVersionBox
            x: 75
            y: 220
            width: 243
            height: 20
            color: "#00000000"
            radius: height/2
            border.width: 0
            border.color: "#0ee8b8"


            Label {
                id: versionLbl
                color: "#79d4d6"
                text: "version 1.0.0"
                horizontalAlignment: Text.AlignLeft
                anchors.fill: parent
                font.family: "Times New Roman"
                fontSizeMode: Text.HorizontalFit
                font.pixelSize: 13
                font.bold: true
                wrapMode: Text.NoWrap
                //        font.family: bMitraFont.name
            }
        }


        Text {
            x: 75
            y: 191
            text: "MME industry"
            font.bold: true
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 19
            color: "#79d4d6"
        }

        Text {
            id: info
            x: 39
            y: 301
            width: 368
            height: 152
            text: "مرا مِهر سیَه چشمان ز سر بیرون نخواهد شد

رقیب آزارها فرمود و جایِ آشتی نگذاشت

مرا روزِ ازل کاری به جز رندی نفرمودند

خدا را محتسب ما را به فریادِ دَف و نِی بخش

مجالِ من همین باشد که پنهان عشقِ او ورزم
"
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            verticalAlignment: Text.AlignRight
            font.pointSize: 10
            font.family: "Times New Roman"
            color: "#79d4d6"
        }


        Text {
            id: info2
            x: 19
            y: 301
            width: 368
            height: 152
            text: "
قضای آسمان است این و دیگرگون نخواهد شد

مگر آهِ سحرخیزان سویِ گردون نخواهد شد؟

هر آن قسمت که آن جا رفت از آن افزون نخواهد شد

که سازِ شرع از این افسانه بی‌قانون نخواهد شد

کنار و بوس و آغوشش چه گویم چون نخواهد شد"


            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            verticalAlignment: Text.AlignLeft
            font.pointSize: 10
            font.family: "Times New Roman"
            color: "#79d4d6"
        }









        Rectangle {
            id: rectangle
            x: 72
            y: 107
            width: 200
            height: 59
            color: "#00000000"

            Image {
                id: image1
                x: 12
                y: -12
                width: 70
                height: 70
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/image/logo.jpg"
            }
        }

    }



    Item {
        id: appProgress
        x: 348
        y: 532
        width: 223
        height: 44


        AnimatedImage {
            id: animationLoading;
            anchors.fill: parent
            playing: true
            source: "qrc:/images/image/loading4.gif"
        }
    }

}
