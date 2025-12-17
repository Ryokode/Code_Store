from app import db


class Question(db.Model):
    __tablename__ = 'questions'
    id = db.Column(db.Integer, primary_key=True)
    question_text = db.Column(db.Text)
    question_type = db.Column(db.Enum('单选题', '多选题', '填空题', '简答题', '判断题'))
    options = db.Column(db.Text)
    answer = db.Column(db.Text)
    image_path = db.Column(db.Text)
    category = db.Column(db.String(255))
    file_name = db.Column(db.String(255))


class UserAnswer(db.Model):
    __tablename__ = 'user_answers'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer)
    question_id = db.Column(db.Integer, db.ForeignKey('questions.id'))
    user_answer = db.Column(db.Text)
    is_correct = db.Column(db.Boolean)


class WrongSet(db.Model):
    __tablename__ = 'wrong_set'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer)
    question_id = db.Column(db.Integer, db.ForeignKey('questions.id'))